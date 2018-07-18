#!/user
import scrapy
from NBA.items import PlayerItem

class NBASpider(scrapy.spiders.Spider):
    name = "NBA"
    allowed_domains = ["stat-nba.com"]
    start_urls = [
        "http://www.stat-nba.com/game/42391.html"
    ]
    
    def parse(self, response):
        pathArray = [
        "normal player_name_out change_color col0 row"
        "normal fgper change_color col3 row"
        "normal fg change_color col4 row"
        "normal fga change_color col5 row"
        "normal threepper change_color col6 row"
        "normal threep change_color col7 row"
        "normal threepa change_color col8 row"
        "normal ftper change_color col9 row"
        "normal ft change_color col10 row"
        "normal fta change_color col11 row"
        "normal ts change_color col12 row"
        "normal trb change_color col13 row"
        "normal orb change_color col14 row"
        "normal drb change_color col15 row"
        "normal ast change_color col16 row"
        "normal stl change_color col17 row"
        "normal blk change_color col18 row"
        "normal tov change_color col19 row"
        "normal pf change_color col20 row"
        "normal pts change_color col21 row"
        ]
        for teams in response.xpath('//table[@class = \"stat_box\"]/tbody'):
            cnt = 0
            for sel in teams.xpath('tr[@class = \"sort\"]'):
                item = PlayerItem()
                for i in range(0, 20):
                    path = 'td[@class = \"[' + pathArray[i] + str(cnt) + '\"]'
                    if(i == 0) : path + 'a/text()'
                    item[i] = sel.xpath(path).extract()
                yield item
                cnt += 1