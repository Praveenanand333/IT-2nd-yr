import tkinter as tk
from cache import Cache
class InputOutputGUI:
    def __init__(self, master):
        self.master = master
        master.title("CACHE-SIMULATOR")
        master.geometry("700x700")

        # create input labels and entries
        self.input1_label = tk.Label(master, text="Cache-Size", font=("Arial", 16), width=10, height=3)
        self.input1_label.place(x=50,y=60)
        self.input1_entry = tk.Entry(master,width=20,font=("Arial", 16))
        self.input1_entry.place(x=200,y=80)

        self.input2_label = tk.Label(master, text="Block-Size", font=("Arial", 16), width=10, height=3)
        self.input2_label.place(x=50,y=150)
        self.input2_entry = tk.Entry(master,width=20,font=("Arial", 16))
        self.input2_entry.place(x=200,y=170)

        self.input3_label = tk.Label(master, text="Associativity", font=("Arial", 16), width=10, height=3)
        self.input3_label.place(x=50,y=240)
        self.input3_entry = tk.Entry(master,width=20,font=("Arial", 16))
        self.input3_entry.place(x=200,y=260)

        self.input4_label = tk.Label(master, text="Read list", font=("Arial", 16), width=10, height=3)
        self.input4_label.place(x=50,y=330)
        self.input4_entry = tk.Entry(master,width=20,font=("Arial", 16))
        self.input4_entry.place(x=200,y=350)

        # create output labels
        self.output1_label = tk.Label(master, text="HITS",  font=("Arial", 16), width=10, height=3)
        self.output1_label.place(x=150,y=500)
        self.output1_value = tk.StringVar()
        self.output1_entry = tk.Entry(master, state="readonly", textvariable=self.output1_value, font=("Arial", 12))
        self.output1_entry.place(x=150,y=600)

        self.output2_label = tk.Label(master, text="MISS", font=("Arial", 16), width=10, height=3)
        self.output2_label.place(x=400,y=500)
        self.output2_value = tk.StringVar()
        self.output2_entry = tk.Entry(master, state="readonly", textvariable=self.output2_value, font=("Arial", 12))
        self.output2_entry.place(x=400,y=600)

        # create submit button
        self.submit_button = tk.Button(master, text="DO", command=self.submit,width=10,height=2,bg='green')
        self.submit_button.place(x=600,y=100)

    def submit(self):
        # get input values
        self.output1_value.set("")
        self.output2_value.set("")
        input1 = int(self.input1_entry.get())
        input2 = int(self.input2_entry.get())
        input3 = int(self.input3_entry.get())
        input4 = str(self.input4_entry.get())

        # perform some computation with the inputs
        ans=Cache(size=input1, block_size=input2, associativity=input3)
        input_list = input4.split(",")
        input_ints = [int(x) for x in input_list]
        
        for i in input_ints:
            ans.read(i)
        output1 = ans.hits
        output2 = ans.misses
        print(output1,output2)
        # update output values
        self.output1_value.set(str(output1))
        self.output2_value.set(str(output2))

root = tk.Tk()
root.configure(bg='lightblue')
gui = InputOutputGUI(root)
root.mainloop()
