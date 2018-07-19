# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html

import json
import codecs
from scrapy.exceptions import DropItem
class WritePipeline(object):

    def process_item(self, item, spider):
        self.file = codecs.open('data/' + item['date'][0] + '.json', "w", encoding = 'utf-8')

        for i in range(0, len(item.data)):
            line = json.dumps(dict(item.data[i]), ensure_ascii=False)+ "\n"
            self.file.write(line)
        
        return item


class DuplicatesPipeline(object):

    def __init__(self):
        self.ids_seen = set()

    def process_item(self, item, spider):
        if item['id'] in self.ids_seen:
            raise DropItem("Duplicate item found: %s" % item)
        else:
            self.ids_seen.add(item['id'])
            return item