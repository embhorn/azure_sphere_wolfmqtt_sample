

 // Hardware definition
#include "hw/azure_sphere_learning_path.h"

// Learning Path Libraries
#include "azure_iot.h"
#include "exit_codes.h"
#include "peripheral_gpio.h"
#include "terminate.h"
#include "timer.h"

// System Libraries
#include "applibs_versions.h"
#include <applibs/gpio.h>
#include <applibs/log.h>
#include <applibs/powermanagement.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "wolfmqtt/mqtt_client.h"

#ifdef WOLFMQTT_MULTITHREAD
#include "examples/multithread/multithread.h"
#else
#include "examples/mqttclient/mqttclient.h"
#endif

/// <summary>
///  Initialize peripherals, device twins, direct methods, timers.
/// </summary>
static void InitPeripheralsAndHandlers(void)
{
    MQTTCtx app_mqttCtx;

    /* init defaults */
    mqtt_init_ctx(&app_mqttCtx);

#ifdef WOLFMQTT_MULTITHREAD
	// call the wolfMQTT multithread client test
    app_mqttCtx.app_name = "AzureSphere wolfMQTT multithread client";
    app_mqttCtx.message = DEFAULT_MESSAGE;
	app_mqttCtx.test_mode = 1;
	multithread_test(&app_mqttCtx);
#else
	// call the wolfMQTT client test
    app_mqttCtx.app_name = "AzureSphere wolfMQTT client";
    app_mqttCtx.message = DEFAULT_MESSAGE;
	app_mqttCtx.test_mode = 1;
	mqttclient_test(&app_mqttCtx);
#endif
}

/// <summary>
///     Close peripherals and handlers.
/// </summary>
static void ClosePeripheralsAndHandlers(void)
{

	lp_timerEventLoopStop();
}

int main(int argc, char* argv[])
{
	lp_registerTerminationHandler();

	InitPeripheralsAndHandlers();

	// Main loop
	while (!lp_isTerminationRequired())
	{
		int result = EventLoop_Run(lp_timerGetEventLoop(), -1, true);
		// Continue if interrupted by signal, e.g. due to breakpoint being set.
		if (result == -1 && errno != EINTR)
		{
			lp_terminate(ExitCode_Main_EventLoopFail);
		}
	}

	ClosePeripheralsAndHandlers();

	Log_Debug("Application exiting.\n");
	return lp_getTerminationExitCode();
}