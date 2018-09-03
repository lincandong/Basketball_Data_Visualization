import scrapy
import string
from NBA.items import ImageItem

class ImageSpider(scrapy.spiders.Spider):
    name = "Image"
    allowed_domains = ["stat-nba.com"]
    start_urls = [
        'http://www.stat-nba.com/teamList.php'
    ]
    origin_urls = 'http://www.stat-nba.com'
    # driver = webdriver.Chrome('C:\Program Files (x86)\Microsoft Visual Studio\Shared\Python36_64\Scripts\chromedriver.exe')

    def parse(self, response):
        for i in response.xpath('//table//a[@class = \"team\"]/@href'):
            link = self.origin_urls + '/' + i.extract()
            yield scrapy.Request(link, callback = self.parse_team, meta = {})


    def parse_team(self, response):
        for season in range(2017, 2018):
            #player names
            for player in response.xpath('//tr[@class = \"sort\"]//a'):
                PlayerName = player.xpath('text()').extract()
                link = self.origin_urls + player.xpath('@href')[0].extract()
                yield scrapy.Request(link, callback = self.parse_player, meta = {'name':PlayerName})

    def parse_player(self, response):
        Image = ImageItem()
        Image['name'] = response.meta['name'][0]
        Image['image_url'] = self.origin_urls + response.xpath('//div[@class = \"image\"]/img/@src')[0].extract()
        yield Image