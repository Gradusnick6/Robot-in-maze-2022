#include "DisappearingObject.h"
#include "Carcas.h"
#include "mySprite.h"

csf::DisappearingObject::DisappearingObject()
	:Carcas(), DisappearingFunctional() {}

csf::DisappearingObject::DisappearingObject(BaseObject* object, Orientation orientation, float flightSpeed, float vanishingRate)
	:Carcas(Object), DisappearingFunctional(this, orientation, flightSpeed, vanishingRate) {}

void csf::DisappearingObject::Reload(BaseObject* object, Orientation orientation, float flightSpeed, float vanishingRate)
{
	Delete();
	*this = DisappearingObject(Object, orientation, flightSpeed, vanishingRate);
	Object = this;
}