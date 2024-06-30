import pandas as pd

data = {
    "name": ["Alice", "Bob", "Charlie", "Alice", "David", "Bob"],
    "email": ["alice@example.com", "bob@example.com", "charlie@example.com", "alice@example.com", "david@example.com", "bob@example.com"],
    "age": [25, 30, 22, 25, 28, 30]
}
df = pd.DataFrame(data).drop_duplicates(subset="email", keep="first")
print(df)
