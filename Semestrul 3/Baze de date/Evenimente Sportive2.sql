CREATE DATABASE EvenimenteSportive2;
GO
USE EvenimenteSportive2;
GO

CREATE TABLE Sporturi (
id_sport INT PRIMARY KEY IDENTITY,
nume VARCHAR(100) NOT NULL, 
descriere VARCHAR(200)
);

CREATE TABLE Locatii (
id_locatie INT PRIMARY KEY IDENTITY,
nume VARCHAR(100) NOT NULL,
adresa VARCHAR(200),
capacitate INT NOT NULL,
contact VARCHAR(200)
);

CREATE TABLE Antrenori (
id_antrenor INT PRIMARY KEY IDENTITY,
nume VARCHAR(100) NOT NULL,
prenume VARCHAR(100) NOT NULL,
contact VARCHAR(200)
);

CREATE TABLE Sponsori (
id_sponsor INT PRIMARY KEY IDENTITY,
nume VARCHAR(100) NOT NULL, 
contact VARCHAR(200),
nivel NVARCHAR(100)
);

CREATE TABLE Echipe (
id_echipa INT PRIMARY KEY IDENTITY,
nume VARCHAR(100) NOT NULL,
tara VARCHAR(100),
id_antrenor INT NOT NULL,
id_sport INT NOT NULL,
FOREIGN KEY (id_antrenor) REFERENCES Antrenori(id_antrenor),
FOREIGN KEY (id_sport) REFERENCES Sporturi(id_sport)
);

CREATE TABLE Atleti (
id_atlet INT PRIMARY KEY IDENTITY,
nume VARCHAR(100) NOT NULL,
prenume VARCHAR(100) NOT NULL,
nationalitate VARCHAR(100),
data_nasterii DATE,
id_echipa INT NOT NULL,
FOREIGN KEY (id_echipa) REFERENCES Echipe(id_echipa)
);

CREATE TABLE Evenimente (
id_eveniment INT PRIMARY KEY IDENTITY,
nume NVARCHAR(150) NOT NULL,
data DATE NOT NULL,
descriere NVARCHAR(200),
id_locatie INT NOT NULL,
id_sport INT NOT NULL,
FOREIGN KEY (id_locatie) REFERENCES Locatii(id_locatie),
FOREIGN KEY (id_sport) REFERENCES Sporturi(id_sport)
);

CREATE TABLE Programari (
id_programare INT PRIMARY KEY IDENTITY,
start_time TIME NOT NULL,
end_time TIME NOT NULL,
descriere VARCHAR(200),
id_eveniment INT NOT NULL,
FOREIGN KEY (id_eveniment) REFERENCES Evenimente(id_eveniment)
);

CREATE TABLE Inregistrari (
id_inregistrare INT PRIMARY KEY IDENTITY,
data_inregistrare DATE NOT NULL DEFAULT GETDATE(),
id_eveniment INT NOT NULL,
id_echipa INT NOT NULL,
id_atlet INT NOT NULL,
FOREIGN KEY (id_eveniment) REFERENCES Evenimente(id_eveniment),
FOREIGN KEY (id_echipa) REFERENCES Echipe(id_echipa),
FOREIGN KEY (id_atlet) REFERENCES Atleti(id_atlet),
CHECK (
	(id_atlet IS NOT NULL AND id_echipa IS NULL) OR
	(id_atlet IS NULL AND id_echipa IS NOT NULL) 
	  )
);

CREATE TABLE Rezultate (
id_rezultat INT PRIMARY KEY IDENTITY,
pozitie INT NOT NULL,
scor DECIMAL(10,2),
id_eveniment INT NOT NULL,
id_atlet INT NOT NULL,
id_echipa INT NOT NULL,
FOREIGN KEY (id_eveniment) REFERENCES Evenimente(id_eveniment),
FOREIGN KEY (id_atlet) REFERENCES Atleti(id_atlet),
FOREIGN KEY (id_echipa) REFERENCES Echipe(id_echipa),
CHECK (
	(id_atlet IS NOT NULL AND id_echipa IS NULL) OR
	(id_atlet IS NULL AND id_echipa IS NOT NULL)
	  )
);

CREATE TABLE SponsorEvenimente (
id_sponsor INT NOT NULL,
id_eveniment INT NOT NULL,
PRIMARY KEY (id_sponsor, id_eveniment),
FOREIGN KEY (id_sponsor) REFERENCES Sponsori(id_sponsor),
FOREIGN KEY (id_eveniment) REFERENCES Evenimente(id_eveniment)
);


INSERT INTO Sporturi (nume, descriere) VALUES
('Fotbal', 'Sport de echipa cu 11 jucatori'),
('Baschet', 'Sport de echipa cu 5 jucatori'),
('Atletism', 'Sport individual'),
('Tenis', 'Sport de echipa sau individual');

INSERT INTO Locatii(nume, adresa, capacitate, contact) VALUES
('Stadion National', 'Bucuresti', 55000, '000-231-4324'),
('Arena Baschet', 'Cluj-Napoca', 8000, '000-221-3467'),
('Sala de atletism', 'Pitesti', 1500, '000-551-4236'),
('Teren de tenis', 'Constanta', 2000, '000-546-7654');

INSERT INTO Antrenori(nume, prenume, contact) VALUES
('Ionescu', 'Mihai', 'mihai.ionescu@gmail.com'),
('Popescu', 'Andrei', 'andrei.popescu@gmail.com'),
('Marinescu', 'Alina', 'alina.marinescu@gmail.com'),
('Georgescu', 'Maria', 'maria.georgescu@gmail.com');

INSERT INTO Sponsori(nume, contact, nivel) VALUES
('BMW Motors', 'contact@bmwmotors.com', 'Platinum'),
('Superbet', 'contact@superbet.com', 'Gold'),
('Bucovina', 'contact@bucovina.com', 'Silver'),
('Timisoreana', 'contact@timisoreana.com', 'Bronze');

INSERT INTO Echipe(nume, tara, id_antrenor, id_sport) VALUES
('Steaua Bucuresti', 'Romania', 1, 1),
('U-Cluj', 'Romania', 2, 2),
('Atletico Pitesti', 'Romania', 3, 3),
('Clubul Tenis CT', 'Romania', 4, 4);

INSERT INTO Atleti(nume, prenume, nationalitate, data_nasterii, id_echipa) VALUES
('Popa', 'Alexandru', 'Romania', '1998-04-10', 9),
('Ionescu', 'Cristian', 'Romania', '2000-07-22', 10),
('Stoica', 'Ana', 'Romania', '1995-11-13', 11),
('Gheorghe', 'Mihnea', 'Romania', '1997-01-05', 12);

INSERT INTO Evenimente(nume, data, descriere, id_locatie, id_sport) VALUES
('Campionatul National', '2024-05-10', 'Competiție de fotbal', 1, 1),
('Turneul de Baschet', '2024-06-15', 'Competiție de baschet', 2, 2),
('Maratonul Pitesti', '2024-07-20', 'Competiție de atletism', 3, 3),
('Open-ul de Tenis', '2024-08-25', 'Competiție de tenis', 4, 4);

INSERT INTO Programari (start_time, end_time, descriere, id_eveniment) VALUES
('09:00', '11:00', 'Meci 1', 13),
('11:30', '13:30', 'Meci 2', 13),
('14:00', '16:00', 'Semifinale', 14),
('16:30', '18:30', 'Finala', 14);

INSERT INTO Inregistrari (data_inregistrare, id_eveniment, id_echipa, id_atlet) VALUES
('2024-05-01', 13, 9, NULL),
('2024-05-01', 13, NULL, 9),
('2024-06-10', 14, 10, NULL),
('2024-07-10', 15, NULL, 11);

INSERT INTO Rezultate (pozitie, scor, id_eveniment, id_atlet, id_echipa) VALUES
(1, 9.8, 1, NULL, 1),
(2, 8.6, 1, NULL, 2),
(1, 10.0, 3, 3, NULL),
(2, 9.5, 3, 4, NULL);

INSERT INTO SponsorEvenimente (id_sponsor, id_eveniment) VALUES
(1, 1),
(2, 1),
(3, 2),
(4, 3);


-- de refacut toate elementele