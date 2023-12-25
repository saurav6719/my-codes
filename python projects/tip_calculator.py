def answer(input_str, start, end):
    substring = input_str[start:end + 1]
    result = ""
    while len(result) <= len(input_str):
        result += substring
    return result



def main():
    str = input("Enter string ")
    start = int(input("Enter starting index "))
    end = int(input("Enterending index  "))
    result = answer(str, start, end)
    print(result)

