# 🕵️‍♂️ Minesweeper AI Chat Plugin for Unreal Engine 5

## 📌 Overview
This Unreal Engine 5 plugin integrates a **Slate-based Chat Window** that interacts with an AI model via **Mistral AI** to generate **Minesweeper grids** based on user input.

### 🎯 Features
✅ **AI-Generated Minesweeper Grids** – Get Minesweeper grids by simply typing a request  
✅ **Slate-Only UI** – No UMG, fully built using Unreal's **Slate UI Framework**  
✅ **Live AI Chat** – The chat refreshes each time you enter a request  
✅ **Regenerate Functionality** – Just re-enter your query to get a new response  

---

## 🚀 Installation & Setup

### **1️⃣ Prerequisites**
- Unreal Engine **5.3** or later
- C++ Project (Blueprint-only projects **are not supported**)
- **Mistral AI API Key** (replace in `MinesweeperAIRequest.cpp`)

### **2️⃣ Adding the Plugin**
1. Place the `MinesButton` plugin in your project's `Plugins/` folder.
2. Open Unreal Engine and enable the **MinesButton** plugin from **Edit → Plugins**.
3. Restart the editor after enabling the plugin.

### **3️⃣ Building the Plugin**
- **If using Visual Studio:**  
  - Open the project in **Visual Studio 2022**  
  - Right-click on **JoinTask.uproject** → Select **Regenerate Visual Studio Project Files**  
  - Build the project (`Ctrl + Shift + B`)  
- **Using Unreal Engine:**  
  - Open **JoinTask.uproject**  
  - Click **Compile** in the editor

---

## 🛠️ How to Use

1. **Open the Chat Window:**  
   - Click the **Minesweeper AI** button in **Unreal Editor's toolbar**  
   - The chat window appears  

2. **Ask AI for a Grid:**  
   - Type a request like `"Generate a 3x3 Minesweeper grid with 1 bomb"`  
   - Press **Enter**  

3. **View & Play the Grid:**  
   - The AI-generated **Minesweeper grid** appears  
   - Click **Play** to generate an interactive grid  

---

## 🛠️ Developer Guide

### **Project Structure**

/MinesButton
│── /Public
│   ├── MinesButton.h             # Plugin Module
│   ├── SChatWidget.h             # Chat UI (Slate)
│   ├── MinesweeperAIRequest.h    # AI API Handler
│   ├── WindowHUD.h               # HUD for UI Management
│── /Private
│   ├── MinesButton.cpp           # Plugin Logic
│   ├── SChatWidget.cpp           # UI Implementation
│   ├── MinesweeperAIRequest.cpp  # AI API Integration
│   ├── WindowHUD.cpp             # HUD Management


### **Key Components**
📌 **Slate UI (`SChatWidget`)**  
- Custom chat interface built **entirely in Slate**  
- Handles **input, AI responses, and dynamic UI updates**  

📌 **AI Requests (`MinesweeperAIRequest`)**  
- Uses **HTTP requests** to communicate with **Mistral AI**  
- Sends **user input** and receives a **Minesweeper grid**  

📌 **HUD (`WindowHUD`)**  
- Manages adding the **chat window** to the game screen  
- Ensures proper cleanup and prevents duplicate widgets  

---

## ❓ Troubleshooting

### **Common Errors**
❌ **Plugin doesn't appear in the editor**  
✔️ Make sure you **enabled the plugin** under **Edit → Plugins**  

❌ **API key error**  
✔️ Replace the API key in **MinesweeperAIRequest.cpp**  

❌ **AI response is incorrect**  
✔️ Try a more **specific prompt** like `"Generate a 5x5 Minesweeper grid with 3 bombs"`  

---

## 📜 License
This project is for educational purposes. **Not for commercial use.**

---

## 📩 Contributions
- Fork the repo  
- Submit pull requests  
- Open issues for bugs/features  

---

## 🤝 Acknowledgments
- **Epic Games** – Unreal Engine  
- **Mistral AI** – AI Model  

---

