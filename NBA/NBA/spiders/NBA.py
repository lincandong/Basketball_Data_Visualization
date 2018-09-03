#!/user
import scrapy
import string
<<<<<<< HEAD
# from selenium import webdriver
from NBA.items import PlayerItem, SeasonItem, TeamItem, PlayerDataItem, TeamDataItem, GlobalVar, TeamPlayer
=======
from NBA.items import PlayerItem, SeasonItem, TeamItem, PlayerDataItem, TeamDataItem, GlobalVar
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d

class NBASpider(scrapy.spiders.Spider):
    name = "NBA"
    allowed_domains = ["stat-nba.com"]
    start_urls = [
        'http://www.stat-nba.com/teamList.php'
    ]
<<<<<<< HEAD
    origin_urls = 'http://www.stat-nba.com'
    gl = GlobalVar()

    # driver = webdriver.Chrome('C:\Program Files (x86)\Microsoft Visual Studio\Shared\Python36_64\Scripts\chromedriver.exe')

    def parse(self, response):
        # cnt = 0
        for i in response.xpath('//table//a[@class = \"team\"]/@href'):
            # if(cnt == 0):
            link = self.origin_urls + '/' + i.extract()
            yield scrapy.Request(link, callback = self.parse_team, meta = {})
            # cnt += 1

=======
    origin_urls = 'http://www.stat-nba.com/'
    gl = GlobalVar()
    def parse(self, response):
        for i in response.xpath('//table//a[@class = \"team\"]/@href'):
            link = self.origin_urls + i.extract()
            yield scrapy.Request(link, callback = self.parse_team, dont_filter=True)
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d

    def parse_team(self, response):
        team = TeamItem()
        team['name'] = response.xpath('//div[@class = \"head\"]/text()').extract()[0]
        team['name'] = team['name'][0: len(team['name'])-1]
        for season in range(2017, 2018):
            SeasonData = SeasonItem()
<<<<<<< HEAD

            #switch to different data table
            # self.driver.get(response.url)
            # button = self.driver.find_element_by_xpath('//a[@id = \"change_season' + str(season) + '\"]')
            # button.click()
            # SeasonData['season'] = button.get_attribute('textContent')

            SeasonData['season'] = response.xpath('//a[@id = \"change_season' + str(season) + '\"]/div/text()').extract()[0]
            #player names
            for player in response.xpath('//tr[@class = \"sort\"]//a'):
                APlayer = TeamPlayer()
                
                PlayerName = player.xpath('text()').extract()
                APlayer['name'] = PlayerName
                APlayer['season'] = SeasonData['season']
                APlayer['team'] = team['name']

                SeasonData.players.append(APlayer)
                link = self.origin_urls + player.xpath('@href')[0].extract()
                yield scrapy.Request(link, callback = self.parse_player, meta = {'playername':PlayerName})

            #team data
            TempData = TeamDataItem()
            for i in range(0, len(self.gl.TeamDataString)):
                TempData[self.gl.TeamDataString[i]] = [response.xpath('//td[@class = \"player_name\"]/../td[' + str(i+2) + ']/text()').extract()[0]]
=======
            SeasonData['season'] = response.xpath('//a[@id = \"change_season2017\"]/div/text()').extract()[0]
            #player names
            for player in response.xpath('//tr[@class = \"sort\"]//a'):
                SeasonData.players.append(player.xpath('text()').extract())
                link = self.origin_urls + player.xpath('@href')[0].extract()
                yield scrapy.Request(link, callback = self.parse_player, dont_filter=True)
            #team data
            TempData = TeamDataItem()
            for i in range(0, len(self.gl.TeamDataString)):
                TempData[self.gl.TeamDataString[i]] = response.xpath('//td[@class = \"player_name\"]/../td[' + str(i+2) + ']/text()').extract()[0]
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
            SeasonData['data'] = TempData
            team.seasons.append(SeasonData)
        yield team

    def parse_player(self, response):
        player = PlayerItem()
<<<<<<< HEAD
        player['name'] = response.meta['playername'][0]
        player['image_url'] = self.origin_urls + response.xpath('//div[@class = \"image\"]/img/@src')[0].extract()
        for year in response.xpath('//table[@id = \"stat_box_avg\"]/tbody/tr[@class = \"sort\"]'):
            PlayerData = PlayerDataItem()
            PlayerData['name'] = player['name']
=======
        player['ID'] = self.gl.number
        self.gl.number += 1
        name = response.xpath('//div[@class = \"name\"]/text()').extract()[0]
        index = name.find('/')
        player['name'] = name[0: index-1]
        for year in response.xpath('//table[@id = \"stat_box_avg\"]/tbody//tr[@class = \"sort\"]'):
            PlayerData = PlayerDataItem()
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
            for i in range(0, len(self.gl.PlayerDataString)):
                if(i == 0 or i == 1) : 
                    path = 'td[' + str(i+2) + ']/a/text()'
                else:
                    path = 'td[' + str(i+2) + ']/text()'
                PlayerData[self.gl.PlayerDataString[i]] = year.xpath(path).extract()
            player.data.append(PlayerData)
        yield player