#include <iostream>

using namespace std;

struct Song {
    char title[100];
    char artist[100];
    float duration;
};

const int maxSongs = 100;
int songCount = 0;

void addSong(Song* playlist) {
    Song newSong;
    cout << "Введите название песни: ";
    cin.getline(newSong.title, sizeof(newSong.title));
    cout << "Введите имя исполнителя: ";
    cin.getline(newSong.artist, sizeof(newSong.artist));
    cout << "Введите продолжительность песни (в минутах): ";
    cin >> newSong.duration;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    playlist[songCount] = newSong;
    songCount++;

    cout << "Песня добавлена в список.\n";
}


void removeSong(Song* playlist) {
    if (songCount == 0) {
        cout << "Список песен пуст.\n";
        return;
    }

    int index;
    cout << "Введите номер песни для удаления (от 1 до " << songCount << "): ";
    cin >> index;

    if (index < 1 || index > songCount) {
        cout << "Неверный номер песни.\n";
        return;
    }

    for (int i = index - 1; i < songCount - 1; ++i) {
        playlist[i] = playlist[i + 1];
    }

    songCount--;

    cout << "Песня удалена из списка.\n";
}

void displayPlaylist(const Song* playlist) {
    if (songCount == 0) {
        cout << "Список песен пуст.\n";
        return;
    }

    cout << "Список песен:\n";
    for (int i = 0; i < songCount; ++i) {
        cout << i + 1 << ". " << "Название: " << playlist[i].title << ", Исполнитель: " << playlist[i].artist
            << ", Продолжительность: " << playlist[i].duration << " мин.\n";
    }
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "rus");

    Song playlist[maxSongs];

    char choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить песню\n";
        cout << "2. Удалить песню\n";
        cout << "3. Вывести список песен\n";
        cout << "4. Выйти\n";
        cout << "Выберите действие (1-4): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case '1':
            addSong(playlist);
            break;
        case '2':
            removeSong(playlist);
            break;
        case '3':
            displayPlaylist(playlist);
            break;
        case '4':
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный ввод. Попробуйте снова.\n";
        }
    } while (choice != '4');

    return 0;
}