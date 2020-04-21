/*************************************************************************
 * This file is part of input-overlay
 * github.con/univrsal/input-overlay
 * Copyright 2020 univrsal <universailp@web.de>.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *************************************************************************/

#pragma once

#include <stdint.h>
#include <QString>
#include <QJsonObject>
#include <vector>
#include <map>

class element_data_holder;

namespace gamepad {
struct bind {
    const char *setting;
    const char *text_box_id;
    uint16_t code;
    bool axis_event; /* true if axis event */
};

class bindings {
protected:
    static std::vector<bind> m_defaults;
    std::map<uint16_t, bind> m_bindings;
    QString m_name;
    QString m_target_device;
public:
    bindings();
    bindings(const QJsonObject &obj);
    void set_binding(uint16_t id, uint16_t binding);
    void write_to_json(QJsonObject &obj) const;
};

extern std::vector<bindings> loaded_bindings;
extern void save_bindings();
extern void load_bindings();
}
