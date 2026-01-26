from django.http import HttpResponse
from django.shortcuts import render, get_object_or_404
from .models import *


def index(request):
    return render(request, "index.html")


def view_all_books(request):
    all_books = Book.objects.all()
    return render(request, "all_books.html", {"books": all_books})


def view_single_book(request, bookid):
    book = get_object_or_404(Book, id=bookid)
    return render(request, "single_book.html", {"book": book})


def view_books_in_year(request, bookyear):
    year_books = Book.objects.filter(year=bookyear)
    return render(request, "all_books.html", {"books": year_books})


def view_books_in_category(request, bookcategory):
    category_books = Book.objects.filter(category=bookcategory)
    return render(request, "all_books.html", {"books": category_books})


def view_books_in_category_and_year(request, bookcategory, bookyear):
    category_books = Book.objects.filter(category=bookcategory, year=bookyear)
    return render(request, "all_books.html", {"books": category_books})
