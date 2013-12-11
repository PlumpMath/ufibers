/* Copyright 2013 Drew Thoreson
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef _FIBER_H_
#define _FIBER_H_

#define FF_NOREF 1

typedef struct fiber* ufiber_t;

int ufiber_init(void);

ufiber_t ufiber_self(void);

int ufiber_create(ufiber_t *fiber, unsigned long flags,
		void *(*start_routine)(void*), void *arg);

int ufiber_join(ufiber_t fiber, void **retval);

void ufiber_yeild(void);

int ufiber_yeild_to(ufiber_t fiber);

void ufiber_exit(void *retval);

void ufiber_ref(ufiber_t fiber);

void ufiber_unref(ufiber_t fiber);

#endif
