import requests
import json
from pyquery import PyQuery as pq
import time

base_url="http://wanimal1983.org/page/{}"

proxies = {"http": "socks5://127.0.0.1:1080", "https": "socks5://127.0.0.1:1080"}#use socks5 proxy
data={
    'User-Agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.81 Safari/537.36',
    'Origin':'http://wanimal1983.org',
    "Referer":'http://wanimal1983.org/'
    }

def get_page(page):
    url=base_url.format(page)
    r=requests.get(url,proxies=proxies)

    if not r.status_code==200:
        print('Page {} request failed'.format(page))
        exit()

    html=r.text
    doc=pq(html)
    imgs=doc('div.post img')

    i=1
    for img in imgs.items():
        img_url=img.attr('src')

        r=requests.get(img_url,proxies=proxies)

        if r.status_code==200:
            path='wanimal/'+str(page)+'-'+str(i)+'.jpg'
            file=open(path,'wb')
            file.write(r.content)
            file.close()
            print(str(page)+'-'+str(i)+'.jpg writed')
        else:
            print(str(page)+'-'+str(i)+'.jpg request failed')

        i+=1

    time.sleep(3)

for p in range(1,103):
    get_page(p)
