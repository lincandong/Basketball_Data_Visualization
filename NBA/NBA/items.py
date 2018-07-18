# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class NbaItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    pass
class PlayerItem(scrapy.Item):
    name = scrapy.Field()
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