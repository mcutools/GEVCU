/*
 * pref_handler.h
 *
 * header for preference handler
 *
 * Created: 3/24/2013 
 *  Author: Collin Kidder
 */ 


#ifndef PREF_HANDLER_H_
#define PREF_HANDLER_H_

#include <Arduino.h>
#include "config.h"
#include "eeprom_layout.h"
#include "mem_cache.h"

#define PREF_MODE_NORMAL  false
#define PREF_MODE_LKG     true

class PrefHandler {
  private:
  uint32_t base_address; //base address for the parent device
  uint32_t lkg_address;
  bool use_lkg; //use last known good config?
  
  public:
  PrefHandler();
  PrefHandler(uint32_t base);
  void LKG_mode(bool mode);
  void write(uint16_t address, uint8_t val);
  void write(uint16_t address, uint16_t val);
  void write(uint16_t address, uint32_t val);
  void read(uint16_t address, uint8_t *val);
  void read(uint16_t address, uint16_t *val);
  void read(uint16_t address, uint32_t *val);
  uint8_t calcChecksum();
  void saveChecksum();
  bool checksumValid();
  
};
	
#endif
