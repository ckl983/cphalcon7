
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "diinterface.h"

#include <Zend/zend_interfaces.h>

#include "kernel/main.h"

zend_class_entry *phalcon_diinterface_ce;

static const zend_function_entry phalcon_diinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_DIInterface, set, arginfo_phalcon_diinterface_set)
	PHP_ABSTRACT_ME(Phalcon_DIInterface, remove, arginfo_phalcon_diinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_DIInterface, get, arginfo_phalcon_diinterface_get)
	PHP_ABSTRACT_ME(Phalcon_DIInterface, getShared, arginfo_phalcon_diinterface_getshared)
	PHP_ABSTRACT_ME(Phalcon_DIInterface, setService, arginfo_phalcon_diinterface_setservice)
	PHP_ABSTRACT_ME(Phalcon_DIInterface, getService, arginfo_phalcon_diinterface_getservice)
	PHP_ABSTRACT_ME(Phalcon_DIInterface, has, arginfo_phalcon_diinterface_has)
	PHP_ABSTRACT_ME(Phalcon_DIInterface, wasFreshInstance, NULL)
	PHP_ABSTRACT_ME(Phalcon_DIInterface, getServices, NULL)
	ZEND_FENTRY(setDefault, NULL, arginfo_phalcon_diinterface_setdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getDefault, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};


/**
 * Phalcon\DIInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_DIInterface){

	PHALCON_REGISTER_INTERFACE_EX(Phalcon, DIInterface, diinterface, zend_ce_arrayaccess, phalcon_diinterface_method_entry);

	return SUCCESS;
}

/**
 * Registers a service in the service container
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 * @return Phalcon\DI\ServiceInterface
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, set);

/**
 * Removes a service from the service container
 *
 * @param string $name
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, remove);

/**
 * Resolves the service based on its configuration
 *
 * @param string $name
 * @param array $parameters
 * @return object
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, get);

/**
 * Resolves a shared service based on their configuration
 *
 * @param string $name
 * @param array $parameters
 * @return object
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, getShared);

/**
 * Sets a service using a raw Phalcon\DI\Service definition
 *
 * @param string $name
 * @param Phalcon\DI\ServiceInterface $rawDefinition
 * @return Phalcon\DI\ServiceInterface
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, setService);

/**
 * Returns the corresponding Phalcon\Di\Service instance for a service
 *
 * @param string $name
 * @return Phalcon\DI\ServiceInterface
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, getService);

/**
 * Check whether the DI contains a service by a name
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, has);

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, wasFreshInstance);

/**
 * Return the services registered in the DI
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, getServices);

/**
 * Set the default dependency injection container to be obtained into static methods
 *
 * @param Phalcon_DIInterface $dependencyInjector
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, setDefault);

/**
 * Return the last DI created
 *
 * @return Phalcon_DIInterface
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, getDefault);

/**
 * Resets the internal default DI
 */
PHALCON_DOC_METHOD(Phalcon_DIInterface, reset);
