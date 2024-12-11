# JsonDBConfigLoader Plugin

## Overview

**JsonDBConfigLoader** is a plugin for Unreal Engine that simplifies the management of database connection configurations. It allows developers to load, edit, and save `.json` files containing database connection details (e.g., `username`, `password`, `hostname`, `port`, etc.) into an Unreal Engine **Data Table** for runtime usage. The plugin also includes a user-friendly GUI for managing `.json` files and database configurations directly within the Unreal Editor.

## Features

1. **Load JSON to Data Table**  
   - Import `.json` files containing database connection information into an Unreal Engine Data Table.  
   - Streamlines runtime usage of database configurations without reading `.json` files during gameplay.

2. **Manage JSON Files via GUI**  
   - View a list of `.json` files and their contents within the plugin's GUI.  
   - Add, remove, or edit `.json` files directly from the interface.

3. **Edit Database Configurations**  
   - Modify database connection details in the GUI, including fields like `username`, `password`, `hostname`, etc.  
   - Save edited configurations directly into the Data Table or back into a `.json` file.

4. **Save Data to JSON**  
   - Export database connection configurations from the GUI to `.json` files for external usage or backup.

5. **User-Friendly Interface**  
   - A straightforward and responsive GUI designed for efficiency, making database configuration management easy.

---

## Installation

1. **Clone or Download the Repository**  
   Clone the plugin repository into your Unreal Engine project `Plugins/` folder:  
   ```bash
   git clone https://github.com/<your-repository>/JsonDBConfigLoader.git
   ```

2. **Enable the Plugin**  
   - Open your Unreal Engine project.  
   - Navigate to `Edit > Plugins`.  
   - Search for "JsonDBConfigLoader" and enable it.  
   - Restart the editor if prompted.

3. **Dependencies**  
   Ensure your project has the **Json Utilities** module enabled for parsing `.json` files.

---

## Usage

1. **Access the Plugin's Tab**  
   - Open the **JsonDBConfigLoader** tab from the `Window > JsonDBConfigLoader` menu.

2. **Load a JSON File**  
   - Click the **Add** button in the GUI to browse for a `.json` file.  
   - The file will be added to the list and displayed in the GUI.

3. **Edit JSON Data**  
   - Select a file from the list.  
   - Modify the database connection details directly in the editable fields.

4. **Save Changes**  
   - Save changes to a Data Table by clicking the **Save to Data Table** button.  
   - Alternatively, save changes back to the `.json` file using the **Save to File** button.

5. **Create New JSON**  
   - Use the **Create** button to define a new database configuration.  
   - Add fields like `username`, `password`, etc., and save it to a new `.json` file.

---

## Example JSON Format

Below is an example of a `.json` file that the plugin can handle:

```json
{
    "DatabaseConfig": {
        "Username": "admin",
        "Password": "password123",
        "Hostname": "127.0.0.1",
        "Port": 5432,
        "DatabaseName": "GameDB"
    }
}
```

---

## Contributions

Contributions, issues, and feature requests are welcome! Feel free to open an issue or submit a pull request on GitHub.

---

## License

[![License: CC BY 4.0](https://licensebuttons.net/l/by/4.0/80x15.png)](http://creativecommons.org/licenses/by/4.0/)

---

## Support

For questions or support, please contact [kongphai_wutt@outlook.co.th] or open an issue on the GitHub repository.
