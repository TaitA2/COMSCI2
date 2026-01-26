from django.db import models


# Create your models here.
class Book(models.Model):
    id = models.AutoField(primary_key=True)
    year = models.IntegerField()
    author = models.TextField()
    price = models.FloatField()
    title = models.TextField()
    synopsis = models.TextField()
    category = models.TextField(default="Classic")
