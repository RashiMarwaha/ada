import math
# string 1 input and splitting word wise
string_a = input("Enter string one:")
res_a = string_a.split()

# string 2 input and splitting word wise
string_b = input("Enter string two:")
res_b = string_b.split()

# string 1 and 2 concatenated
string_c = res_a + res_b
print(string_c)

# unique list of words
uniqueVocab = []
for word in string_c:
    if word in uniqueVocab:
        continue
    else:
        uniqueVocab.append(word)
print(uniqueVocab)

# length or number of unique words
lengthFinal = len(uniqueVocab)
print(lengthFinal)

# alphabetical sorting
uniqueVocab.sort()
print(uniqueVocab)

# frequency count for each word
list_a = []
list_b = []

for word in uniqueVocab:
    countOfWord = string_a.count(word)
    list_a.append(countOfWord)
print(list_a)

for word in uniqueVocab:
    countOfWord = string_b.count(word)
    list_b.append(countOfWord)
print(list_b)

# cosTheta = a.b / |a||b|
# cos0 = 1
# cos90 = 0

# dot product
dot_product = 0
for i in range(0,lengthFinal):
    dot_product = list_a[i]*list_b[i] + dot_product

print("Dot Product: " , dot_product)

# magnitude
magnitude_a = 0
magnitude_b = 0
for i in range(0,lengthFinal):
    magnitude_a = magnitude_a + (list_a[i]*list_a[i])
    magnitude_b = magnitude_b + (list_b[i]*list_b[i])

print("Magnitude of a: " , magnitude_a)
print("Magnitude of b: " , magnitude_b)

mag_a = round(math.sqrt(magnitude_a),4)
mag_b = round(math.sqrt(magnitude_b),4)

print("Final magnitude of a: " , mag_a)
print("Final magnitude of b: " , mag_b)

magnitude = round((mag_a * mag_b),4)
print("Final magnitude: " , magnitude)

# cos theta
cos_value = round((dot_product / magnitude),4)
print("Cos Theta: " , cos_value)

# final output
print(round((cos_value*100),2) , "% similarity")






