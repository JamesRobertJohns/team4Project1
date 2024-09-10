import os

# Constants
MIN_SIZE = 10**3
MAX_SIZE = 10 * 10**6
SCALE_FACTOR = 10

def check_file_elements(file_name, expected_count):
    try:
        with open(file_name, 'r') as file:
            lines = file.readlines()
            actual_count = len(lines)
            if actual_count == expected_count:
                print(f"[+] {file_name} is correct. Contains {actual_count} elements.")
            else:
                print(f"[-] {file_name} is incorrect. Expected {expected_count}, found {actual_count} elements.")
    except FileNotFoundError:
        print(f"[-] File {file_name} not found.")
    except Exception as e:
        print(f"[-] Error reading {file_name}: {e}")

def main():
    file_index = 1
    expected_count = MIN_SIZE

    while expected_count <= MAX_SIZE:
        file_name = f'input_{file_index}.txt'
        check_file_elements(file_name, expected_count)
        
        file_index += 1
        expected_count *= SCALE_FACTOR

if __name__ == "__main__":
    main()
