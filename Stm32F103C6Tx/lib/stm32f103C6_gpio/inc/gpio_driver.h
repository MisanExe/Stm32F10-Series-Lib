#ifndef _GPIO_DRV_
#define _GPIO_DRV_

#include "driver_base.h"
#include <array>

	typedef enum
	{
		CNF_INPUT_ANALOG,
		CNF_INPUT_FLOATING,
		CNF_INPUT_PULL_UP_DOWN,
		CNF_OUTPUT_PUSH_PULL,
		CNF_OUTPUT_OPEN_DRAIN,
		CNF_OUTPUT_AF_PUSH_PULL,
		CNF_OUTPUT_AF_OPEN_DRAIN,
		MODE_INPUT_RESET,
		MODE_OUTPUT_10MHZ,
		MODE_OUTPUT_2MHZ,
		MODE_OUTPUT_50MHZ,

	}GPIO_CONFIG_E;



	typedef struct{
		uint32_t pin;
		GPIO_PORT_E port;
		GPIO_CONFIG_E config;
	}pin_port_t;



	namespace gpio{
			void init_gpio(GPIO_t *io, uint8_t pin, GPIO_CONFIG_E mode, GPIO_CONFIG_E cnf);
			void SetHIGH(GPIO_t *io, uint8_t pin);
			void SetLOW(GPIO_t *io, uint8_t pin);
	};

#endif
