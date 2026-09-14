import requests
from bs4 import BeautifulSoup as bt
from lxml import etree as xm

res = requests.get("https://minfin.com.ua/ua/currency/usd/")
b = bt(res.text, "html.parser")
table = b.find("table")
rows = table.find_all("tr")
row = rows[1]
row = row.find_all("td")
print(row[2])


  #  //*[@id="root"]/div/section/div/div/div/div/section[1]/div[2]/div[1]/div[2]/table/tbody/tr/td[2]/div