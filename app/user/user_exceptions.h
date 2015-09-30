#include "c_types.h"
#include "rom.h"
#include <xtensa/corebits.h>

#define TEXT_SECTION_ATTR __attribute__((section(".text")))
#define RAM_CONST_ATTR __attribute__((section(".text")))

void load_non_32_wide_handler (struct exception_frame *ef, uint32_t cause) TEXT_SECTION_ATTR;
