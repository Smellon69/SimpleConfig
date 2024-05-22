#pragma once

#include "archivex.h"

#include <shlobj.h>
#include <fstream>
#include <filesystem>
#include <vector>
#include <Windows.h>
#include <map>
#include <string>

class c_config
{
private:
	std::filesystem::path path;
	std::vector<std::string> configs;

public:
	void run(std::string name);
	void load(size_t id);
	void save(size_t id) const;
	void add(std::string name);
	void remove(size_t id);
	void rename(size_t item, std::string new_name);
	void reset();

	constexpr auto& get_configs() { return configs; };
	constexpr auto& get_path() { return path; };

	struct
	{

	// Implement your features here.
	int testInt;

        HWND window = NULL;
	} feature;
};

inline auto config = c_config();
