
/*
 * Nekohook: Free, fast and modular cheat software
 * Copyright (C) 2018 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <cstring>  // String stuff
#include <ctime>    // Time
#include <iostream>

#include "logging.hpp"

namespace neko {

// Nekohooks main logging util
Log debug_log(fs::temp_directory_path() / "nekohook.log", [](std::string& in) {
    std::time_t current_time = std::time(nullptr);

    char time_str[16];
    std::strftime(time_str, sizeof(time_str), "%H:%M:%S",
                  std::localtime(&current_time));

    in = std::string("[Neko] [") + time_str + "] " + in;
});

}  // namespace neko