// Copyright 2018 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <chrono>
#include <string>
#include <discord.h>
#include "common/common_types.h"
#include "core/core.h"
#include "core/loader/loader.h"
#include "yuzu/discord_impl.h"
#include "yuzu/discord_intf.h"
#include "yuzu/uisettings.h"

namespace DiscordSDK {

DiscordImpl::DiscordImpl() {

    // The number is the client ID for yuzu, it's used for images and the
    // application name
    auto result = discord::Core::Create(693588302414086234, DiscordCreateFlags_Default, &core);

}

DiscordImpl::~DiscordImpl() {
    core->ActivityManager().ClearActivity([](discord::Result result) {

    });
    //    Discord_Shutdown();
    //    There is no more shutting down...
}

void DiscordImpl::Pause() {
    core->ActivityManager().ClearActivity([](discord::Result result) {

    });
}

void DiscordImpl::Update() {
    s64 start_time = std::chrono::duration_cast<std::chrono::seconds>(
                         std::chrono::system_clock::now().time_since_epoch())
                         .count();
    std::string title;
    if (Core::System::GetInstance().IsPoweredOn())
        Core::System::GetInstance().GetAppLoader().ReadTitle(title);

    discord::Activity activity{};
    discord::ActivityAssets &assets = activity.GetAssets();
    discord::ActivityTimestamps &timestamps = activity.GetTimestamps();

    activity.GetAssets().SetLargeImage("yuzu_logo");
    activity.GetAssets().SetLargeText("yuzu is an emulator for the Nintendo Switch");
    if (Core::System::GetInstance().IsPoweredOn()) {
        activity.SetState(title.c_str());
        activity.SetDetails("Currently in game");
    } else {
        activity.SetDetails("Not in game");
    }

    activity.GetTimestamps().SetStart(start_time);

    core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {

    });
}
} // namespace DiscordSDK
