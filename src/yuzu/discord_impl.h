// Copyright 2018 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <discord.h>
#include "yuzu/discord_intf.h"

namespace DiscordSDK {

class DiscordImpl : public DiscordInterface {
private:
    discord::Core* core;
public:
    DiscordImpl();
    ~DiscordImpl() override;

    void Pause() override;
    void Update() override;
    void Tick() override;
};

} // namespace DiscordSDK
