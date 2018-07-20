# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy

class GlobalVar:
    number = 0
    total = 30
    PlayerDataString = [
        'season',
        'tm',
        'g',
        'gs',
        'mp',
        'fgper',
        'fg',
        'fga',
        'threepper',
        'threep',
        'threepa',
        'ftper',
        'ft',
        'fta',
        'trb',
        'orb',
        'drb',
        'ast',
        'stl',
        'blk',
        'tov',
        'pf',
        'pts',
        'w',
        'l'
    ]
    TeamDataString = [
        'g',
        'wg',
        'lg',
        'fgper',
        'fg',
        'fga',
        'threepper',
        'threep',
        'threepa',
        'ftper',
        'ft',
        'fta',
        'trb',
        'orb',
        'drb',
        'ast',
        'stl',
        'blk',
        'tov',
        'pf',
        'pts'    
    ]

class PlayerDataItem(scrapy.Item):
    season = scrapy.Field()
    tm = scrapy.Field()
    g = scrapy.Field()
    gs = scrapy.Field() #首发
    mp = scrapy.Field()
    fgper = scrapy.Field()
    fg = scrapy.Field()
    fga = scrapy.Field()
    threepper = scrapy.Field()
    threep = scrapy.Field()
    threepa = scrapy.Field()
    ftper = scrapy.Field()
    ft = scrapy.Field()
    fta = scrapy.Field()
    trb = scrapy.Field()
    orb = scrapy.Field()
    drb = scrapy.Field()
    ast = scrapy.Field()
    stl = scrapy.Field()
    blk = scrapy.Field()
    tov = scrapy.Field()
    pf = scrapy.Field()
    pts = scrapy.Field()
    w = scrapy.Field()
    l = scrapy.Field()

class TeamDataItem(scrapy.Item):
    g = scrapy.Field()
    wg = scrapy.Field()
    lg = scrapy.Field()
    fgper = scrapy.Field()
    fg = scrapy.Field()
    fga = scrapy.Field()
    threepper = scrapy.Field()
    threep = scrapy.Field()
    threepa = scrapy.Field()
    ftper = scrapy.Field()
    ft = scrapy.Field()
    fta = scrapy.Field()
    ts = scrapy.Field()
    trb = scrapy.Field()
    orb = scrapy.Field()
    drb = scrapy.Field()
    ast = scrapy.Field()
    stl = scrapy.Field()
    blk = scrapy.Field()
    tov = scrapy.Field()
    pf = scrapy.Field()
    pts = scrapy.Field()

class PlayerItem(scrapy.Item):
    ID = scrapy.Field()
    name = scrapy.Field()
    data = []

class SeasonItem(scrapy.Item):
    season = scrapy.Field()
    players = []
    data = scrapy.Field()

class TeamItem(scrapy.Item):
    name = scrapy.Field()
    seasons = []