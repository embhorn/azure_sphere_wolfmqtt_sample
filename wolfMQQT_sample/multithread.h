/* multithread.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.
 *
 * This file is part of wolfMQTT.
 *
 * wolfMQTT is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfMQTT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#ifndef WOLFMQTT_MULTITHREAD_H
#define WOLFMQTT_MULTITHREAD_H

#include "examples/mqttexample.h"
#include <errno.h>
#include <stdlib.h>


#define PRINTF Log_Debug


/* Exposed functions */
int multithread_test(MQTTCtx *mqttCtx);
int sample(void);


#endif /* WOLFMQTT_MULTITHREAD_H */