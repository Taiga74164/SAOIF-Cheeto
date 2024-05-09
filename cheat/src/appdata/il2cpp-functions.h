// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2018.4.18 - 2018.4.33

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************

using namespace app;

// C# Methods
DO_APP_FUNC(0x00942130, String*, Marshal_PtrToStringAnsi, (void* ptr, MethodInfo* method));
DO_APP_FUNC(0x009421F0, String*, Marshal_PtrToStringUni, (void* ptr, MethodInfo* method));

DO_APP_FUNC(0x01086A70, String*, Encoding_GetString, (Encoding* __this, Byte__Array* bytes, MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x02B515E8, Encoding_GetString__MethodInfo);
DO_APP_FUNC(0x01087690, Encoding*, Encoding_get_UTF8, (MethodInfo* method));
// Unity Methods

// Game Methods
DO_APP_FUNC(0x01A5A490, void, UncheaterManager_UncheaterCallback_OnHackDetected, (void/*UncheaterManager_UncheaterCallback*/* __this, uint32_t code, uint32_t wp, String* path, MethodInfo* method));
DO_APP_FUNC(0x01A5A4F0, void, UncheaterManager_UncheaterCallback_OnSend, (UncheaterManager_UncheaterCallback* __this, Byte__Array* buffer, MethodInfo* method));
DO_APP_FUNC(0x00688820, void, EnumElementAttribute__ctor, (EnumElementAttribute* __this, String* displayName, MethodInfo* method));
DO_APP_FUNC(0x00621010, ClientSocket*, GameManager_get_NetClient, (GameManager* __this, MethodInfo* method));
DO_APP_FUNC(0x014EEEF0, bool, ClientSocket_SendPacket, (ClientSocket* __this, void/*PacketBase*/* packet, MethodInfo* method));


// Singletons
DO_APP_FUNC(0x01DC68B0, GameManager*, Singleton_1_SAO_Game_GameManager__get_Instance, (MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x02B273C0, Singleton_1_SAO_Game_GameManager__get_Instance__MethodInfo);

// Functions found manually
DO_APP_FUNC(0x01B0230, void*, GetClass, (int64_t typeInfo));