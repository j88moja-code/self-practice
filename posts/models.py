from django.db import models
from django.contrib.auth.models import User

class Post(models.Model):

    title = models.CharField(max_length=200)
    url = models.URLField()
    poster = models.ForeignKey(User, on_delete=models.CASCADE)
    created_at = models.DateTimeField(auto_now_add=True)

    class Meta:
        ordering = ['-created_at']
        verbose_name_plural = 'Posts'
    def __str__(self):
        return self.title

class Vote(models.Model):

    voter = models.ForeignKey(User, on_delete=models.CASCADE)
    post = models.ForeignKey(Post, on_delete=models.CASCADE)
