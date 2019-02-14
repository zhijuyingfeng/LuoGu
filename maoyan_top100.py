import re
import requests
from bs4 import BeautifulSoup

base_url="https://maoyan.com/board/4?offset={}"
offset=0

pattern=re.compile('class="board-item-content".*?title="(.*?)".*?class="star">(.*?)</p>.*?class="releasetime">(.*?)</p>.*?class="integer">(.*?)</i>.*?class="fraction">(\d+)</i>',re.S)

def get_page(offset):
    url=base_url.format(offset)
    r=requests.get(url)
    text=r.text
    
    movies=re.findall(pattern,text)
    
    for movie in movies:
        print(movie[0])
        #print(movie[1])
        actor=movie[1]
        actor=re.sub('\s+',"",actor)
        print(actor)
        print(movie[2])
        print(movie[3],movie[4],'\n')

for i in range(0,10):
    get_page(i*10)