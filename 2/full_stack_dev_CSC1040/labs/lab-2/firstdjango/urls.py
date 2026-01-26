from django.contrib import admin
from django.urls import path, include
from .views import *

urlpatterns = [
    path("", index, name="index"),
    path("contact/", index, name="index"),
    path("books", view_all_books, name="all_books"),
    path("books/<int:bookid>", view_single_book, name="single_book"),
    path("books/year/<int:bookyear>", view_books_in_year, name="year_books"),
    path("books/category/<str:bookcategory>", view_books_in_category, name="category_books"),
    path("books/category/<str:bookcategory>/year/<int:bookyear>", view_books_in_category_and_year, name="category_books"),
]
