#include "gpio_driver.h"

/*
 *  helper functions
 */
static void port_config_mode(GPIO_t *io, uint32_t pin, GPIO_CONFIG_E config);
static void port_config_cnf(GPIO_t *io, uint32_t pin, GPIO_CONFIG_E config);
//static void port_config_reset(GPIO_t *io, uint32_t pin);


/**
 * @brief :
 * @param :
 * @return :
 */
static uint32_t ConvertPinNo(uint8_t pin)
{
	return   pin > 7 ? pin % 8 : pin;
}

/*@brief :  initalize the input/output
 *@param :  GPIO_t * io (pointer to GPIO_t structure)
 *		 	uint8_t pin (pin number ranging from 0 - 31)
 *		 	GPIO_CONFIG_E mode (enum of pin modes for stm32F1 series mcu)
 *		 	GPIO_CONFIG_E cnf (cnf configuration of the pin)
 *@return : None
 */
void gpio::init_gpio(GPIO_t *io, uint8_t pin, GPIO_CONFIG_E mode, GPIO_CONFIG_E cnf)
{
	// ensure pin range between 0 - 31
	if (pin < 0 || pin >31){
		return;
	}

	// Set all RCC
	RCC->APB2ENR |= (0B11111<<2); //to-do : set individual bit's for RCC

	// Set mode Config
	port_config_mode(io, pin, mode);

	// Set cnf Config
	port_config_cnf(io, pin, cnf);

}

/**
 * @brief :
 * @param :
 * @return :
 */
static void port_config_mode(GPIO_t *io, uint32_t pin, GPIO_CONFIG_E config){

	uint32_t pinNum = ConvertPinNo(pin);

	switch(config)
	{
		case MODE_INPUT_RESET : //0b00
			if(pin < 7){
				io->CRL &= ~(1U<<(pinNum*4));
				io->CRL &= ~(1U<<((pinNum*4)+1));

			}else{
				io->CRH &= ~(1U<<(pinNum*4));
				io->CRH &= ~(1U<<((pinNum*4)+1));
			}
			break;
		case MODE_OUTPUT_2MHZ: //0b10
			if(pin < 7){
				io->CRL &= ~(1U<<(pinNum*4));
				io->CRL |= (1U<<((pinNum*4)+1));

			}else{
				io->CRH &= ~(1U<<(pinNum*4));
				io->CRH |= (1U<<((pinNum*4)+1));
			}
			break;
		case MODE_OUTPUT_10MHZ: //0b01
			if(pin < 7){
				io->CRL |= (1U<<(pinNum*4));
				io->CRL &= ~(1U<<((pinNum*4)+1));

			}else{
				io->CRH |= (1U<<(pinNum*4));
				io->CRH &= ~(1U<<((pinNum*4)+1));
			}
			break;
		case MODE_OUTPUT_50MHZ://0b11
			if(pin < 7){
				io->CRL |= (1U<<(pinNum*4));
				io->CRL |= (1U<<((pinNum*4)+1));

			}else{
				io->CRH |= (1U<<(pinNum*4));
				io->CRH |= (1U<<((pinNum*4)+1));
			}
			break;
		default:
			break;
	}

}
/**
 * @brief :
 * @param :
 * @return :
 */
static void port_config_cnf(GPIO_t *io, uint32_t pin, GPIO_CONFIG_E config)
{

	uint32_t pinNum = ConvertPinNo(pin);
	//set
	switch(config)
		{
			case CNF_INPUT_ANALOG: //0b00
				if(pin < 7){
					io->CRL &= ~(1U<<((pinNum*4)+2));
					io->CRL &= ~(1U<<((pinNum*4)+3));

				}else{
					io->CRH &= ~(1U<<((pinNum*4)+2));
					io->CRH &= ~(1U<<((pinNum*4)+3));
				}
				break;
			case CNF_INPUT_FLOATING: //0b01
				if(pin < 7){
					io->CRL |= (1U<<((pinNum*4)+2));
					io->CRL &= ~(1U<<((pinNum*4)+3));

				}else{
					io->CRH |= (1U<<((pinNum*4)+2));
					io->CRH &= ~(1U<<((pinNum*4)+3));
				}
				break;
			case CNF_INPUT_PULL_UP_DOWN: //0b10
				if(pin < 7){
					io->CRL &= ~(1U<<((pinNum*4)+2));
					io->CRL |= (1U<<((pinNum*4)+3));

				}else{
					io->CRH &= ~(1U<<((pinNum*4)+2));
					io->CRH |= (1U<<((pinNum*4)+3));
				}
				break;
			case CNF_OUTPUT_PUSH_PULL: //0b00
				if(pin < 7){
					io->CRL &= ~(1U<<((pinNum*4)+2));
					io->CRL &= ~(1U<<((pinNum*4)+3));

				}else{
					io->CRH &= ~(1U<<((pinNum*4)+2));
					io->CRH &= ~(1U<<((pinNum*4)+3));
				}
				break;
			case CNF_OUTPUT_OPEN_DRAIN: //0b01
				if(pin < 7){
					io->CRL |= (1U<<((pinNum*4)+2));
					io->CRL &= ~(1U<<((pinNum*4)+3));

				}else{
					io->CRH |= (1U<<((pinNum*4)+2));
					io->CRH &= ~(1U<<((pinNum*4)+3));
				}
				break;
			case CNF_OUTPUT_AF_PUSH_PULL: //0b10
				if(pin < 7){
					io->CRL &= ~(1U<<((pinNum*4)+2));
					io->CRL |= (1U<<((pinNum*4)+3));

				}else{
					io->CRH &= ~(1U<<((pinNum*4)+2));
					io->CRH |= (1U<<((pinNum*4)+3));
				}
				break;
			case CNF_OUTPUT_AF_OPEN_DRAIN: //0b11
				if(pin < 7){
					io->CRL |= (1U<<((pinNum*4)+2));
					io->CRL |= (1U<<((pinNum*4)+3));

				}else{
					io->CRH |= (1U<<((pinNum*4)+2));
					io->CRH |= (1U<<((pinNum*4)+3));
				}
				break;

			default:
				break;
		}

}
/**
 * @brief :
 * @param :
 * @return :
 */
//static void port_config_reset(GPIO_t *io, uint32_t pin){
//	uint32_t pinNum = ConvertPinNo(pin);
//
//	if(pin < 7){
//		io->CRL &= ~(0xF<<(pinNum*4));
//	}else{
//		io->CRH &= ~(0xF<<(pinNum*4));
//	}
//}

/**
 * @brief : set pin high
 * @param : io (pointer to io type)
 * @return : pin ( pin number ranging from 0 - 31)
 */
void gpio::SetHIGH(GPIO_t *io, uint8_t pin){
	io->ODR |= (1U<<pin);
}

/**
 * @brief : reset pin
 * @param : io (pointer to io type)
 * 			pin (pin number ranging from 0 -31)
 * @return : None
 */
void gpio::SetLOW(GPIO_t *io, uint8_t pin){
	io->ODR &= ~(1U<<pin);
}
