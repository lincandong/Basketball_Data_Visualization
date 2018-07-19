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
        "normal player_name_out change_color col0 row",
        "normal fgper change_color col3 row",
        "normal fg change_color col4 row",
        "normal fga change_color col5 row",
        "normal threepper change_color col6 row",
        "normal threep change_color col7 row",
        "normal threepa change_color col8 row",
        "normal ftper change_color col9 row",
        "normal ft change_color col10 row",
        "normal fta change_color col11 row",
        "normal ts change_color col12 row",
        "normal trb change_color col13 row",
        "normal orb change_color col14 row",
        "normal drb change_color col15 row",
        "normal ast change_color col16 row",
        "normal stl change_color col17 row",
        "normal blk change_color col18 row",
        "normal tov change_color col19 row",
        "normal pf change_color col20 row",
        "normal pts change_color col21 row",
        "current gs change_color col1 row",
        "normal mp change_color col2 row"
        ]
        for teams in response.xpath('//table[@class = \"stat_box\"]/tbody'):
            cnt = 0
            for sel in teams.xpath('tr[@class = \"sort\"]'):
                item = PlayerItem()
                path = 'td[@class = \"' + pathArray[0] + str(cnt) + '\"]/a/text()'
                item['name'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[20] + str(cnt) + '\"]/text()'
                item['gs'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[21] + str(cnt) + '\"]/text()'
                item['mp'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[1] + str(cnt) + '\"]/text()'
                item['fgper'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[2] + str(cnt) + '\"]/text()'
                item['fg'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[3] + str(cnt) + '\"]/text()'
                item['fga'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[4] + str(cnt) + '\"]/text()'
                item['threepper'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[5] + str(cnt) + '\"]/text()'
                item['threep'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[6] + str(cnt) + '\"]/text()'
                item['threepa'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[7] + str(cnt) + '\"]/text()'
                item['ftper'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[8] + str(cnt) + '\"]/text()'
                item['ft']= sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[9] + str(cnt) + '\"]/text()'
                item['fta'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[10] + str(cnt) + '\"]/text()'
                item['ts']= sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[11] + str(cnt) + '\"]/text()'
                item['trb'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[12] + str(cnt) + '\"]/text()'
                item['orb'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[13] + str(cnt) + '\"]/text()'
                item['drb'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[14] + str(cnt) + '\"]/text()'
                item['ast'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[15] + str(cnt) + '\"]/text()'
                item['stl'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[16] + str(cnt) + '\"]/text()'
                item['blk'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[17] + str(cnt) + '\"]/text()'
                item['tov'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[18] + str(cnt) + '\"]/text()'
                item['pf'] = sel.xpath(path).extract()
                path = 'td[@class = \"' + pathArray[19] + str(cnt) + '\"]/text()'
                item['pts'] = sel.xpath(path).extract()
                yield item
                cnt += 1