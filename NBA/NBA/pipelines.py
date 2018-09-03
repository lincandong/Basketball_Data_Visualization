# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html

import json
import codecs
import sys
<<<<<<< HEAD
import scrapy
from scrapy.exceptions import DropItem
from NBA.items import PlayerItem, TeamItem, ImageItem
from scrapy.pipelines.images import ImagesPipeline
=======
from scrapy.exceptions import DropItem
from NBA.items import PlayerItem, TeamItem
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
class WritePipeline(object):

    def process_item(self, item, spider):
        if(isinstance(item, PlayerItem)):
            self.file = codecs.open('./data/players/' + item['name'] + '.json', "w", encoding = 'utf-8')
            self.file.write('[\n')
            for i in range(0, len(item.data)):
<<<<<<< HEAD
                if(item.data[i]['name'] == item['name']):
                    content = dict(item.data[i])
                    del content['name']
                    self.file.write(json.dumps(content, ensure_ascii=False))
                    if(i < len(item.data)-1):
                        self.file.write(',')
                    self.file.write('\n')
            self.file.write(']')
            pass
        elif(isinstance(item, TeamItem)):
            for S in item.seasons:
                self.file = codecs.open('./data/teams/' + S['season'] + '/' + item['name'] + '.json', "w", encoding = 'utf-8')
                self.file.write('[\n{\"season\": [' + json.dumps(S['season'], ensure_ascii=False) + "]},\n")
                for player in S.players:
                    if(player['team'] == item['name'] and player['season'] == S['season']):
                        content = dict(player)
                        del content['season']
                        del content['team']
                        self.file.write(json.dumps(content, ensure_ascii=False))
                        self.file.write(',\n')
                self.file.write(json.dumps(dict(S['data']), ensure_ascii=False) + "\n]")
        return item
    
=======
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
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d


class FilterPipeline(object):

    def __init__(self):
        self.ids_seen = set()

    def process_item(self, item, spider):
        if(isinstance(item, PlayerItem)):
<<<<<<< HEAD
            if item['name'] in self.ids_seen:
                raise DropItem("Duplicate item found: %s" % item)
            self.ids_seen.add(item['name'])
            return item
        else:
            return item

class ImagePipeline(ImagesPipeline):
    
    def get_media_requests(self, item, info):
        if(isinstance(item, ImageItem)):
            yield scrapy.Request(item['image_url'], meta = {'item':item, 'PlayerName':item['name']})
            pass

    def item_completed(self, results, item, info):
        if(isinstance(item, ImageItem)):
            image_paths = [x['path'] for ok, x in results if ok]      # ok判断是否下载成功
            if not image_paths:
                raise DropItem("Item contains no images")
        #item['image_paths'] = image_paths
        return item

    def file_path(self, request, response=None, info=None):
        if(isinstance(request.meta['item'], ImageItem)):
            down_file_name = u'/full/{0}.jpg'.format(request.meta['PlayerName'])
            return down_file_name
=======
            if item['ID'] in self.ids_seen:
                raise DropItem("Duplicate item found: %s" % item)
            else:
                self.ids_seen.add(item['ID'])
                return item
        else:
            return item
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
