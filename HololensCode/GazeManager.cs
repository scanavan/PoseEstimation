using HoloToolkit;
using UnityEngine;

/// <summary>
/// GazeManager determines the location of the user's gaze, hit position and normals.
/// </summary>
public class GazeManager : Singleton<GazeManager>
{
    [Tooltip("Maximum gaze distance for calculating a hit.")]
    public float MaxGazeDistance = 5.0f;

    [Tooltip("Select the layers raycast should target.")]
    public LayerMask RaycastLayerMask = Physics.DefaultRaycastLayers;

    /// <summary>
    /// Physics.Raycast result is true if it hits a Hologram.
    /// </summary>
    public bool Hit { get; private set; }

    /// <summary>
    /// HitInfo property gives access
    /// to RaycastHit public members.
    /// </summary>
    public RaycastHit HitInfo { get; private set; }

    /// <summary>
    /// Position of the user's gaze.
    /// </summary>
    public Vector3 Position { get; private set; }

    /// <summary>
    /// RaycastHit Normal direction.
    /// </summary>
    public Vector3 Normal { get; private set; }

    private GazeStabilizer gazeStabilizer;
    private Vector3 gazeOrigin;
    private Vector3 gazeDirection;

    void Awake()
    {
        /* TODO: DEVELOPER CODING EXERCISE 3.a */

        // 3.a: GetComponent GazeStabilizer and assign it to gazeStabilizer.
        gazeStabilizer = GetComponent<GazeStabilizer>();
    }

    private void Update()
    {
        // 2.a: Assign Camera's main transform position to gazeOrigin.
        gazeOrigin = Camera.main.transform.position;

        // 2.a: Assign Camera's main transform forward to gazeDirection.
        gazeDirection = Camera.main.transform.forward;

        // 2.a: Assign Position to be gazeOrigin plus MaxGazeDistance times gazeDirection.
        Position = gazeOrigin + (gazeDirection * MaxGazeDistance);

        // 2.a: Assign Normal to be the user's gazeDirection.
        Normal = gazeDirection;
    }
}