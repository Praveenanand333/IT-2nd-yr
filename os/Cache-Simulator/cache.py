class Cache:
    def __init__(self, size, block_size, associativity):
        self.size = size
        self.block_size = block_size
        self.associativity = associativity
        self.num_blocks = size // block_size
        self.num_sets = self.num_blocks // associativity
        self.cache = [[None] * associativity for _ in range(self.num_sets)]
        self.hits = 0
        self.misses = 0

    def read(self, address):
        tag, set_index, block_offset = self._split_address(address)
        block_index = set_index * self.associativity

        for i in range(self.associativity):
            block = self.cache[set_index][i]
            if block is not None and block.tag == tag:
                self.hits += 1
                return block.data[block_offset]

        self.misses += 1
        block = self._fetch_block(tag, block_index)
        return block.data[block_offset]

    def _fetch_block(self, tag, block_index):
        block = Block(tag, self.block_size)
        self.cache[block_index % self.num_sets][block_index % self.associativity] = block
        return block

    def _split_address(self, address):
        mask = (1 << self.num_sets.bit_length()) - 1
        set_index = (address >> self.block_size.bit_length()) & mask
        tag = address >> (self.block_size.bit_length() + self.num_sets.bit_length())
        block_offset = address & (self.block_size - 1)
        return tag, set_index, block_offset


class Block:
    def __init__(self, tag, size):
        self.tag = tag
        self.data = bytearray(size)
cache = Cache(size=1024, block_size=64, associativity=2)
for i in range(16):
    cache.read(i*10)
print(cache.hits, cache.misses)  # prints 8 8
