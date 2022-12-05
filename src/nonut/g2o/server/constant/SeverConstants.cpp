#include "ServerConstants.h"

#include "Constant.h"
#include "Property.h"

namespace nonut::g2o
{
    void SharedConstants::init()
    {
        SQObject constTable = getConstTable();

#define GET_CONST(constName)                               \
    Property<Int> constName##Prop(#constName, constTable); \
    (constName) = constName##Prop.get()

        GET_CONST(AC_SPEED_HACK);
        
        GET_CONST(DISCONNECTED);
        GET_CONST(LOST_CONNECTION);
        GET_CONST(HAS_CRASHED);

        GET_CONST(TALENT_SNEAK);
        GET_CONST(TALENT_PICK_LOCKS);
        GET_CONST(TALENT_PICKPOCKET);
        GET_CONST(TALENT_RUNES);
        GET_CONST(TALENT_ALCHEMY);
        GET_CONST(TALENT_SMITH);
        GET_CONST(TALENT_THROPHY);
        GET_CONST(TALENT_ACROBATIC);
        GET_CONST(TALENT_REGENERATE);
        GET_CONST(TALENT_FIREMASTER);
        GET_CONST(TALENT_PICKPOCKET_UNUSED);
        GET_CONST(TALENT_A);
        GET_CONST(TALENT_B);
        GET_CONST(TALENT_C);
        GET_CONST(TALENT_D);
        GET_CONST(TALENT_E);
    }
}
