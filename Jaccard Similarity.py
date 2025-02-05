
def jaccard(string1, string2):
    word_a =  set(string1.split())
    word_b =  set(string2.split())
    intersection = len(word_a.intersection(word_b))
    union = len(word_a.union(word_b))
    return (intersection / union)*100


string_a = input("Enter string one:")
string_b = input("Enter string two:")
print("% jaccard similarity: " , jaccard(string_a,string_b))
