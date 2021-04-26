#ifndef __MODULE_HACKS_H__
#define __MODULE_HACKS_H__

#include "Module.h"

class ModuleHacks : public Module {
public:

	update_status PreUpdate() override;
};

#endif