# 📊 Record Viewer & Regression Analysis App

This application is a Qt-based GUI for managing historical data records and performing linear/spline regression visualization. It features dialogs for adding/editing records, displays for viewing historical data, and dynamic charts for regression analysis.

---

## 📁 Project Structure

.
├── CMakeLists.txt # Project build configuration
├── main.cpp # Entry point
├── *.cpp / *.h # Core source files
├── *.ui # Qt Designer UI files
├── icons/ # UI icons (SVG)
├── images/ # Background and other UI images
└── resources.qrc # Qt resource file

markdown
Copy
Edit

---

## ✅ Features

- 📂 Add, edit, and delete data records
- 📈 Linear and spline regression visualizations
- 🧮 Statistical summary computation (mean, stddev, etc)
- 🎨 Modern Qt-based user interface using `.ui` files and SVG icons

---

## 🛠️ Build & Run (Using Qt Creator)

1. **Install Qt and Qt Creator**  
   - Download and install from [https://www.qt.io/download](https://www.qt.io/download)  
   - Make sure to install:
     - The Qt version (e.g., Qt 5.15 or Qt 6.x)
     - Qt Creator IDE
     - A compiler toolchain (MSVC, MinGW, or GCC depending on your OS)

2. **Open the Project**
   - Launch **Qt Creator**
   - Go to `File` → `Open File or Project...`
   - Choose the `CMakeLists.txt` file (or `.pro` file if you're using qmake)

3. **Configure the Kit**
   - Select your preferred **Qt version** and **compiler kit**
   - Qt Creator will automatically generate the build configuration

4. **Build the Project**
   - Click the **hammer icon** (🔨) or press **Ctrl+B** to build

5. **Run the App**
   - Click the **green play button** (▶) or press **Ctrl+R**

---

## 📝 Notes

- If you're using **CMake**, open the `CMakeLists.txt` file.
- If using **qmake**, open the `.pro` file instead.
- The `.user` file (e.g., `CMakeLists.txt.user`) is **local to your machine** and should not be committed to version control.

---

## 🧩 Dependencies

Make sure the following are installed via the Qt Maintenance Tool:
- Qt base modules (Widgets, Charts)
- Appropriate compiler (GCC/Clang/MinGW/Visual Studio)

---

## 🧪 Optional TODOs

- [ ] Add data persistence (e.g., SQLite)
- [ ] Export charts as images
- [ ] Improve UI styling
- [ ] Add unit tests for `Statistics` and `HistoryData`

---

## 🖼️ Credits

Icons in `icons/` are likely sourced from open icon packs such as Material Design or Feather.
