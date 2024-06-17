from Crypto.Hash import MD5

# Generating the MD5 hash dictionary
def generate_md5_dict():
    charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ{}_"
    md5_dict = {}
    for char in charset:
        md5 = MD5.new()
        md5.update(char.encode())
        md5_hash = md5.hexdigest()
        md5_dict[md5_hash] = char
    return md5_dict

# Decrypting the flag from output.txt
def decrypt_flag(md5_dict):
    flag = ""
    with open("output.txt", "r") as file:
        for line in file:
            # Extracting the hash from the line
            hash_ = line.split(" = ")[1].strip()
            # Finding the corresponding character
            if hash_ in md5_dict:
                flag += md5_dict[hash_]
            else:
                flag += "?"
    return flag

md5_dict = generate_md5_dict()
flag = decrypt_flag(md5_dict)
print(f"Decrypted flag: {flag}")
