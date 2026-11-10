import requests
from bs4 import BeautifulSoup
import numpy as np
import matplotlib.pyplot as plt

def predict_next(x):
    n = len(x)
    if n < 2:
        return x[0] if n == 1 else 0

    a = n * (n + 1) * (2 * n + 1) / 6
    r = n * (n + 1) / 2
    
    p = sum((i + 1) * x[i] for i in range(n))
    q = sum(x)

    s = a * n - r * r 
    k = (p * n - r * q) / s
    b = (a * q - p * r) / s 

    next_value = k * (n + 1) + b
    return next_value, k, b

cur = []
datef = 1
datet = 22
for i in range(datef, datet+1):
    url = f"https://bank.gov.ua/ua/markets/exchangerates?date={i}.09.2026&period=daily"
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    soup = soup.find_all(id = "exchangeRates")[0].find_all("tbody")[0].find_all("tr")[8].find_all("td")[4]
    cur.append(float(soup.get_text().replace(',', '.')))

a, k, b = predict_next(cur)
cur.append(a)
print(cur)

x_values = range(1, len(cur) + 1)
y = [k * i + b for i in x_values]

plt.plot(x_values, cur, marker='o', linestyle='-', color='b', label='Дані')
plt.plot(x_values, y, linestyle='-', color='y')

plt.title("Графік курсу USD")
plt.xlabel("Одиничний час")
plt.ylabel("Курс")
plt.grid(True)

plt.show()