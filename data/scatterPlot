import matplotlib.pyplot as plt

def read_data(file_name):
    try:
        with open(file_name, 'r') as file:
            data = [int(line.strip()) for line in file.readlines()]
        return data
    except FileNotFoundError:
        print(f"[-] File {file_name} not found.")
        return []
    except Exception as e:
        print(f"[-] Error reading file {file_name}: {e}")
        return []

def generate_scatter_plot(data, file_name):
    if not data:
        print(f"[-] No data to plot from file {file_name}")
        return

    x_values = list(range(1, len(data) + 1)) 
    y_values = data 

    plt.figure(figsize=(10, 6))
    plt.scatter(x_values, y_values, s=10, c='blue', alpha=0.5)
    plt.title(f'Scatter Plot for {file_name}')
    plt.xlabel('Index')
    plt.ylabel('Integer Values')
    plt.grid(True)
    
    plt.show()

def main():
    file_name = 'input_1.txt'  # Change the name to plot scatter plot for other files
    
    data = read_data(file_name)
    
    generate_scatter_plot(data, file_name)

if __name__ == "__main__":
    main()
