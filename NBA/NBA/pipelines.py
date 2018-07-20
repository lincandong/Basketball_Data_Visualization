# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html

import json
import codecs
import sys
from scrapy.exceptions import DropItem
from NBA.items import PlayerItem, TeamItem
class WritePipeline(object):

    def process_item(self, item, spider):
        if(isinstance(item, PlayerItem)):
            self.file = codecs.open('./data/players/' + item['name'] + '.json', "w", encoding = 'utf-8')
            self.file.write('[\n')
            for i in range(0, len(item.data)):
                self.file.write(json.dumps(dict(item.data[i]), ensure_ascii=False))
                if(i < len(item.data)-1):
                    self.file.write(',')
                self.file.write('\n')
            self.file.write(']')
        elif(isinstance(item, TeamItem)):
            for S in item.seasons:
                self.file = codecs.open('./data/teams/' + S['season'] + '/' + item['name'] + '.json', "w", encoding = 'utf-8')
                self.file.write('[\n[' + json.dumps(S['season'], ensure_ascii=False) + "],\n[\n")
                for player in S.players:
                    self.file.write(json.dumps(player, ensure_ascii=False))
                    print("begin")
                    if(player != S.players[len(S.players)-1]):
                        self.file.write(',')
                    self.file.write('\n')
                self.file.write('],\n' + json.dumps(dict(S['data']), ensure_ascii=False) + "\n]")
        return item


class FilterPipeline(object):

    def __init__(self):
        self.ids_seen = set()

    def process_item(self, item, spider):
        if(isinstance(item, PlayerItem)):
            if item['ID'] in self.ids_seen:
                raise DropItem("Duplicate item found: %s" % item)
            else:
                self.ids_seen.add(item['ID'])
                return item
        else:
            return item