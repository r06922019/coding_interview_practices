class Codec:

    def __init__(self):
        self.urls = []
        self.prefix = "http://tinyurl.com/"

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        self.urls.append(longUrl)
        return self.prefix + str(len(self.urls)-1)

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        index = shortUrl[len(self.prefix):]
        return self.urls[int(index)]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
