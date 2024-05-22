# SimpleConfig

SimpleConfig is a lightweight C++ library for easy configuration management. It provides a simple API for loading, parsing, and manipulating configuration files. Designed for efficiency and minimal dependencies, it's perfect for projects needing straightforward config handling.

## Features

- **Path Management**: Automatically determines and manages the configuration path within the user's AppData directory.
- **Config Listing**: Lists all configuration files in the specified directory.
- **Load Configurations**: Loads configuration data from a specified file.
- **Save Configurations**: Saves current configuration data to a specified file.
- **Add Configurations**: Adds a new configuration file by name.
- **Remove Configurations**: Removes a specified configuration file.
- **Rename Configurations**: Renames an existing configuration file.
- **Reset Configurations**: Resets the configuration data to default values.

## Usage

### Including the Library

```cpp
#include "config.h"
```

### Usage

```cpp
c_config configManager;

// Run the config manager and set the config directory name. A good place for this would be your processes main.
// Maybe in your dllmain or int main.
configManager.run("MyAppConfigs");

// Set a variable.
int test = configManager.feature.testInt;

```

### ImGUI Example

```cpp
ImGui::SetNextWindowPos(ImVec2(300, 300), ImGuiCond_FirstUseEver);
ImGui::Begin("Config", &configWindow);

constexpr auto& config_items = config.get_configs();
static auto current_config = -1;

if ((size_t)(current_config) >= config_items.size())
  current_config = -1;

static char buffer[32];

ImGui::Text("Configs");

if (ImGui::ListBox("config_list", &current_config, [](void* data, int idx, const char** out_text)
{
    auto& vector = *(std::vector<std::string> *)(data);
    *out_text = vector[idx].c_str();
    return true;
}, &config_items, (int)(config_items.size()), 5) && current_config != -1) strcpy_s(buffer, config_items[current_config].c_str());

if (ImGui::InputText("config_name", buffer, IM_ARRAYSIZE(buffer), ImGuiInputTextFlags_EnterReturnsTrue))
{
  if (current_config != -1)
    config.rename(current_config, buffer);
}

if (ImGui::Button("Create", ImVec2(60, 25)))
  config.add(buffer);

ImGui::SameLine();

if (ImGui::Button("Reset", ImVec2(60, 25)))
  config.reset();

ImGui::SameLine();

if (current_config > -1)
{
  if (ImGui::Button("Save", ImVec2(60, 25)))
    config.save(current_config);

  ImGui::SameLine();

  if (ImGui::Button("Load", ImVec2(60, 25)))
    config.load(current_config);

  ImGui::SameLine();

  if (ImGui::Button("Delete", ImVec2(60, 25)))
    config.remove(current_config);
}
```

### License

SimpleConfig is released under the MIT License. See the [LICENSE](LICENSE) file for more details.
