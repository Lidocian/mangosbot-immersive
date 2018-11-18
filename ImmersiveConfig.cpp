#include "immersivepch.h"
#include "../../shared/SystemConfig.h"
#include "ImmersiveConfig.h"

using namespace std;

INSTANTIATE_SINGLETON_1(ImmersiveConfig);

ImmersiveConfig::ImmersiveConfig()
{
}

bool ImmersiveConfig::Initialize()
{
    sLog.outString("Initializing Immersive by ike3");

    if (!config.SetSource(SYSCONFDIR"immersive.conf"))
    {
        sLog.outString("Immersive is Disabled. Unable to open configuration file immersive.conf");
        return false;
    }

    fallDamageHC = config.GetBoolDefault("Immersive.FallDamageHardCore", true);
      if (!fallDamageHC){
        Fdamg = 14.57f;
         sLog.outString("Falldamage changed to Normal in immersive.conf");}
      else{
         Fdamg = 4.57f;
         sLog.outString("Falldamage changed to HardCore in immersive.conf");}

    serverPort = config.GetIntDefault("Immersive.ServerPort", 0);
    manualAttributes = config.GetBoolDefault("Immersive.ManualAttributes", true);
    sharedXpPercent = config.GetFloatDefault("Immersive.sharedXpPercent", 90.0f);
    sharedRepPercent = config.GetFloatDefault("Immersive.sharedRepPercent", 90.0f);

    sLog.outString("Immersive configuration loaded");
    return true;
}
