// Player interface

import java.util.ArrayList;
import java.util.List;

interface Player {
    void joinGame();

    void leaveGame();

    void sendMessage(String message);

    void receiveMessage(String message);

    String getPlayerType();

    String getName();
}

// Abstract Player class
abstract class AbstractPlayer implements Player {
    // Fields
    protected String name;
    protected GameLobby lobby;

    // Constructor
    public AbstractPlayer(String name, GameLobby lobby) {
        this.name = name;
        this.lobby = lobby;
    }

    @Override
    public void sendMessage(String message) {
        lobby.sendMessage(message, this);
    }

    @Override
    public void receiveMessage(String message) {
        System.out.println("[" + this.name + "] received: \"" + message + "\"");
    }

    @Override
    public void joinGame() {
        lobby.registerPlayer(this);
    }

    @Override
    public void leaveGame() {
        lobby.removePlayer(this);
    }

    public String getName() {
        return this.name;
    }

    public abstract String getPlayerType();
}

// Concrete human player type
class HumanPlayer extends AbstractPlayer {

    // Constructor
    public HumanPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "HumanPlayer";
    }
}

// AI player class
class AIPlayer extends AbstractPlayer {

    // Constructor
    public AIPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "AIPlayer";
    }
}

// Spectator player class
class Spectator extends AbstractPlayer {

    // Constructor
    public Spectator(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "Spectator";
    }
}

// Admin player class
class AdminPlayer extends AbstractPlayer {
    public AdminPlayer(String name, GameLobby lobby) {
        super(name, lobby);
    }

    @Override
    public String getPlayerType() {
        return "AdminPlayer";
    }

    public void kickPlayer(String name) {
        lobby.kickPlayer(name, this);
    }
}

// Game Lobby (Mediator) class
class GameLobby {
    // Registered players
    private List<Player> players;

    // Constructor
    public GameLobby() {
        this.players = new ArrayList<>();
    }

    // Register method
    void registerPlayer(Player player) {
        this.players.add(player);
        System.out.println(
                "[GameLobby] " + player.getPlayerType() + " " + player.getName() + " has joined the lobby.");
    }

    // Remove method
    void removePlayer(Player player) {
        this.players.remove(player);
        System.out.println(
                "[GameLobby] " + player.getPlayerType() + " " + player.getName() + " has left the lobby.");
    }

    // Send message method
    void sendMessage(String message, Player sender) {
        if (sender.getPlayerType() == "Spectator") {
            System.out.println("[GameLobby] Spectators cannot send messages.");
            return;
        }
        System.out.println("[" + sender.getName() + "] sends: \"" + message + "\"");
        System.out.println("[GameLobby] Message from " + sender.getName() + ": \"" + message + "\"");

        // call receiveMessage on all other players
        for (Player receiver : players) {
            if (receiver != sender) {
                receiver.receiveMessage(message);
            }
        }
    }

    // kick player method
    void kickPlayer(String name, AdminPlayer admin) {
        for (Player p : players) {
            if (p.getName().equals(name)) {
                System.out.println("[GameLobby] Admin " + admin.getName() + " kicked " + p.getPlayerType() + " "
                        + p.getName() + " from the lobby.");
                this.removePlayer(p);
                return;
            }
        }
        System.out.println("[GameLobby] Player " + name + " not found.");

    }

    void startMatch() {
        List<Player> activePlayers = new ArrayList<>();
        for (Player p : players) {
            if (!p.getPlayerType().equals("Spectator") && !p.getPlayerType().equals("AdminPlayer")) {
                activePlayers.add(p);
            }
        }
        if (activePlayers.size() < 2) {
            System.out.println("[GameLobby] Not enough players to start a match.");
        } else {
            System.out.print("[GameLobby] Starting game with players: " + activePlayers.get(0).getName());

            for (int i = 1; i < activePlayers.size(); i++) {
                System.out.print(", " + activePlayers.get(i).getName());
            }
            System.out.println();

        }
    }
}
