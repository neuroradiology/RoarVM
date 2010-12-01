/******************************************************************************
 *  Copyright (c) 2008 - 2010 IBM Corporation and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *    David Ungar, IBM Research - Initial Implementation
 *    Sam Adams, IBM Research - Initial Implementation
 *    Stefan Marr, Vrije Universiteit Brussel - Port to x86 Multi-Core Systems
 ******************************************************************************/


#include <pthread.h>

/**
 * A simplified version of the OS_Interface used in the RoarVM.
 * It provides only functionallity required by tests.
 *
 * It is defined here as the standard OS_Interface for tests.
 */
class   Test_OS_Interface;
typedef Test_OS_Interface OS_Interface;


class Test_OS_Interface {
public:
  
  typedef pthread_mutex_t Mutex;
  
  static inline void mutex_init(Mutex* mutex, const pthread_mutexattr_t* attr = NULL) {
    pthread_mutex_init(mutex, attr);
  }
  
  static inline void mutex_destruct(Mutex* mutex) {
    pthread_mutex_destroy(mutex);
  }
  
  static inline int mutex_lock(Mutex* mutex) {
    return pthread_mutex_lock(mutex);
  }
  
  static inline int mutex_trylock(Mutex* mutex) {
    return pthread_mutex_trylock(mutex);
  }
  
  static inline int mutex_unlock(Mutex* mutex) {
    return pthread_mutex_unlock(mutex);
  }

};
