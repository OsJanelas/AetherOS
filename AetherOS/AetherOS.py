import tkinter as tk
import os, datetime

class AetherOS:
    def __init__(self, root):
        self.root = root
        self.root.title("AetherOS v2.0")
        self.root.geometry("800x600")
        self.root.config(bg="#004a7c")
        
        self.draw_start()

    def draw_start(self):
        apps = [
            ("Notas", "#008a00", lambda: os.system("notepad")),
            ("Arquivos", "#1da1f2", lambda: os.system("explorer .")),
            ("Calculadora", "#e671b8", lambda: os.system("calc")),
            ("Shell", "#7b4b94", lambda: os.system("start cmd")),
            ("Calendário", "#ff8100", lambda: print(datetime.datetime.now()))
        ]
        
        for i, (name, color, cmd) in enumerate(apps):
            btn = tk.Button(self.root, text=name, bg=color, fg="white", 
                            width=20, height=8, command=cmd, relief="flat")
            btn.grid(row=i//3, column=i%3, padx=10, pady=10)

if __name__ == "__main__":
    root = tk.Tk()
    AetherOS(root)
    root.mainloop()